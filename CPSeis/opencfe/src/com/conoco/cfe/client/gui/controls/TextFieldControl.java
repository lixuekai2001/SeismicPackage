///
/// TextFieldControl.java
///
///     Date       Author   Alterations
///----------------------------------------------------------------------------
///  9.
///  8. 09-11-2002 SMCook   Added getPreferredSize() function to inner class
///                          to improve appearance of crowded process screens.
///                          The new logic factors the box height by 0.75.
///  7. 09-05-2002 SMCook   Removed debug code.
///  6. 08-23-2002 SMCook   Added message statement for setText exception case
///                          and cleaned up tabs and source code alignment.
///  5. 08-02-2002 SMCook   Replaced JPasteField with JTextField due to
///                          support for cut and paste being an inherent
///                          feature of Java 1.4.  Removed all references to
///                          JPasteField (also removed from com/conoco/shared
///                          the underlying related XClipboard support classes).
///  4. 10-08-2001 SMCook   Added call '_document.setModified(false)' in
///                          ReturnAction to prevent unnecessary repeated
///                          calls to back end.
///

package com.conoco.cfe.client.gui.controls;

import com.conoco.cfe.client.ClientConstants;

import com.conoco.cfe.client.application.Console;

import com.conoco.cfe.client.gui.controls.text.TextFieldDocument;

import com.conoco.cfe.utils.ArrayList;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Color;

import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseListener;
import java.awt.event.FocusListener;
import java.awt.event.FocusEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.Hashtable;

import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.KeyStroke;
import javax.swing.JComponent;

import javax.swing.text.Keymap;
import javax.swing.text.Document;
import javax.swing.text.BadLocationException;

/**
 * A GUI control that encapsulates a text field.
 */
public class TextFieldControl extends GUIControlAdapter
  implements FieldGUIControl {
  /**
   * Static inializer to remove the default 'enter' key binding.
   */
  static {
    JTextField f = new JTextField();
    KeyStroke enter = KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0);
    Keymap map = f.getKeymap();
    map.removeKeyStrokeBinding(enter);
  }  

  /**
   * Variable for storing the text field contained by this control
   * 
   * @serial
   */
  protected JTextField     _field;

  /**
   * Variable for storing the document that will be used by 
   * the text field
   * 
   * @serial
   */
  protected TextFieldDocument _document;

  /**  
   * A variable for the listener object that gets notified 
   * when the component gains focus
   *
   * @serial
   */ 
  protected FocusListener _focusListener;

  /**
   * Variable for the listener object that gets a notification
   * when the button component detects a mouse enter
   *
   * @serial
   */
  protected MouseListener _mListener;

  /** 
   * variable for key listener
   * 
   * @serial
   */
  protected KeyListener _keyListener;

  /**
   * Constructs a text field control. 
   */      
  public TextFieldControl() {
    super();
    _field = new MyTextField();
    _document = createDocument();
    _focusListener = new FocusWatcher();
    _mListener = new MyMouseListener();
    _field.setDocument(_document);
    _field.addFocusListener(_focusListener);
    _field.addMouseListener(_mListener);
    //register the Enter key
    _field.registerKeyboardAction( new ReturnAction(), "Return",
                  KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0),
                      JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);
  }

  /**
   * Creates the document that will be used by the text field.
   * 
   * @return the document that will be used by the text field
   */
  protected TextFieldDocument createDocument() {
    return new TextFieldDocument();
  }
 
  /**
   * Sets he font on this control.
   * 
   * @param f the desired font
   */
  public void setFont(Font f) {
    _field.setFont(f);
  }

  /**
   * Sets the sensitivity of this control.
   * 
   * @param sensitive the boolean flag that is true if 
   *           this control is to be sensitive; false otherwise
   */
  public void setSensitive(boolean sensitive) {
    _field.setEnabled(sensitive);
    _field.setEditable(sensitive);   //SMCook -- makes box gray when insensitive
  }
 
  /**
   * Sets whether this control is editable or not.
   * 
   * @param editable   the boolean flag that is true if
   *           this control is to be editable; false otherwise
   */
  public void setEditable(boolean editable) {
    _field.setEditable(editable);
  }

  /**
   * Posts a request for obtaining focus. 
   * 
   * @param rowNumber this parameter is applicable only to array and arrayset
   *           controls; fields and other controls disregard this parameter
   */
  public void requestFocus(int rowNumber) {
    _field.requestFocus();  
  }
 
  /**
   * Sets the text on this field.
   * 
   * @param value the text to be set on this field
   */
  public void setValue(String value) {     
     _field.setText(value);
  }

  /**
   * Dummy method.
   */
  public void setItems(String[] items) {
  }

  /**
   * Returns the GUI component being encapsulated by this control. 
   * This method will be invoked typically by a GUI builder for adding
   * this control to the GUI.
   * 
   * @return the GUI component contained by this control
   */
  public Component getComponent() {
    return _field;
  }

  /**
   * Sets the number of columns on this field.
   * 
   * @param columns   number of columns    
   */
  public void setColumns(int columns) {
    _field.setColumns(columns);
    _document.setMaxLength(columns);
  }

  /**
   * Returns the number of columns in this text field.
   * 
   * @return the number of columns in this text field control
   */
  public int getColumns() {
    return _field.getColumns();
  }
 
  /**
   * Disposes this control.
   */
  public void dispose() {
    _field.removeFocusListener(_focusListener) ;
    super.dispose();
  }

  /**
   * Inner class that sends focus-related notifications to the
   * GUI control listeners.
   */
  class FocusWatcher implements FocusListener {
    /**
     * This method is invoked when focus is gained by this 
     * control
     * 
     * @param e the event that is generated when focus
     *       is gained by this control
     */
    public void focusGained(FocusEvent e) {
      /**
       * Implementation of red outline when the component has the focus
       */
      _field.setBorder(BorderFactory.createLineBorder(Color.red, 2));
      _document.setModified(false);

      GUIControlEvent event = new 
        GUIControlEvent(TextFieldControl.this, 
          GUIControlEvent.COMPONENT_FOCUS_EVENT,
            null);
      try {
        fireGUIControlChanged(event);
      } 
      catch (GUIControlException en) {
        System.err.println("Text Field Focus Exception");  
      }
    }

    /**
     * This method is invoked when focus is lost by this 
     * control
     * 
     * @param e the event that is generated when focus
     *       is lost by this control
     */    
    public void focusLost(FocusEvent e) {
      /**
      * Return border to default
      */
      _field.setBorder(BorderFactory.createEtchedBorder());
      if (_document.isModified()) {
        GUIControlEvent event = new 
          GUIControlEvent(TextFieldControl.this, 
            GUIControlEvent.MODIFY_FIELD_EVENT,
              _field.getText());
        try {
          fireGUIControlChanged(event);
        } 
        catch (GUIControlException en) {
        }
      }
    }
  }

  /**
   * Inner class that implements a mouse listener to listen 
   * to mouse events on this control.
   */      
  class MyMouseListener extends MouseAdapter {
    /**
     * Method that is invoked when the button detects a mouse click
     * interaction added for bug #103.
     */
    public void mouseClicked(MouseEvent e){
      if (!_field.isEditable()) {
        GUIControlEvent event = new 
          GUIControlEvent(TextFieldControl.this, 
            GUIControlEvent.ITEM_CLICKED_EVENT,
              "");
        try {
          fireGUIControlChanged(event);
        } 
        catch (GUIControlException en) {
          System.err.println("TextFieldControl mouseclicked Exception");  
        }    
      }
    }
 
    /**
     * Method that is invoked when the button detects a mouse enter.
     */
    public void mouseEntered(MouseEvent e) {
      GUIControlEvent event = new 
        GUIControlEvent(TextFieldControl.this, 
          GUIControlEvent.MOUSE_ENTERED_EVENT,
            null);
      try {
        fireGUIControlChanged(event);
      } 
      catch (GUIControlException en) {
        System.err.println("TextFieldControl: Exception");  
      }
    }  
  }

  /**
   * Inner class that implements the "Return" key action on this text field.
   */
  protected class ReturnAction implements ActionListener {
    public void actionPerformed(ActionEvent e) {  
      if (_document.isModified()) {
        GUIControlEvent event = new 
          GUIControlEvent(TextFieldControl.this, 
            GUIControlEvent.MODIFY_FIELD_EVENT,
              _field.getText());
        try {
          fireGUIControlChanged(event);
        } 
        catch (GUIControlException en) {
          System.err.println("TextFieldControl ReturnAction Exception");  
        }
      _document.setModified(false);        //SMCook added
      }
    }
  } 

  /**
   */
  protected class MyTextField extends JTextField {

    /**
     * Reduce the default text field height.
     * 
     */
    public Dimension getPreferredSize() {
      Dimension d = super.getPreferredSize();
      d.height = (int)(.75 * d.height);
      return d;
    }

    /**
     * Sets the text on this field.
     * 
     * @param value the text to be set on this field
     */
    public void setText(String value) {     
      try {
        Document doc = getDocument();
        doc.remove(0, doc.getLength());
        doc.insertString(0, value, null);
      } 
      catch (BadLocationException e) {
        StringBuffer buf = new StringBuffer();
        for (int i=0; i<TextFieldControl.this.getColumns(); i++) {
          buf.append("0");  
        }
        try {
          Document doc = getDocument();
          doc.remove(0, doc.getLength());
          doc.insertString(0, buf.toString(), null);
        } 
        catch (Exception en) {
          Console.logMessage(this, en.toString());  //SMCook - silent
                                                    // exception undesirable
        }
      }     
    }
  }
}
