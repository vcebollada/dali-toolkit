//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.10
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Dali {

using System;
using System.Runtime.InteropServices;


public class PropertyNotification : BaseHandle {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal PropertyNotification(global::System.IntPtr cPtr, bool cMemoryOwn) : base(NDalicPINVOKE.PropertyNotification_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(PropertyNotification obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~PropertyNotification() {
    DisposeQueue.Instance.Add(this);
  }

  public override void Dispose() {
    if (!Window.IsInstalled()) {
      DisposeQueue.Instance.Add(this);
      return;
    }

    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          NDalicPINVOKE.delete_PropertyNotification(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }



/**
  * @brief Event arguments that passed via Notify signal
  *
  */
public class NotifyEventArgs : EventArgs
{
   private PropertyNotification _propertyNotification;

   /**
     * @brief PropertyNotification - is the PropertyNotification handle that has the notification properties.
     *
     */
   public PropertyNotification PropertyNotification
   {
      get
      {
         return _propertyNotification;
      }
      set
      {
         _propertyNotification = value;
      }
   }
}

  [UnmanagedFunctionPointer(CallingConvention.StdCall)]
  private delegate void NotifyEventCallbackDelegate(IntPtr propertyNotification);
  private DaliEventHandler<object,NotifyEventArgs> _propertyNotificationNotifyEventHandler;
  private NotifyEventCallbackDelegate _propertyNotificationNotifyEventCallbackDelegate;

  /**
    * @brief Event for Notified signal which can be used to subscribe/unsubscribe the event handler
    * (in the type of NotifyEventHandler-DaliEventHandler<object,NotifyEventArgs>) provided by the user.
    * Notified signal is emitted when the notification upon a condition of the property being met, has occurred.
    */
  public event DaliEventHandler<object,NotifyEventArgs> Notified
  {
     add
     {
        lock(this)
        {
           // Restricted to only one listener
           if (_propertyNotificationNotifyEventHandler == null)
           {
              _propertyNotificationNotifyEventHandler += value;

              _propertyNotificationNotifyEventCallbackDelegate = new NotifyEventCallbackDelegate(OnPropertyNotificationNotify);
              this.NotifySignal().Connect(_propertyNotificationNotifyEventCallbackDelegate);
           }
        }
     }

     remove
     {
        lock(this)
        {
           if (_propertyNotificationNotifyEventHandler != null)
           {
              this.NotifySignal().Disconnect(_propertyNotificationNotifyEventCallbackDelegate);
           }

           _propertyNotificationNotifyEventHandler -= value;
        }
     }
  }

  // Callback for PropertyNotification NotifySignal
  private void OnPropertyNotificationNotify(IntPtr propertyNotification)
  {
     NotifyEventArgs e = new NotifyEventArgs();
     e.PropertyNotification  = GetPropertyNotificationFromPtr(propertyNotification);

     if (_propertyNotificationNotifyEventHandler != null)
     {
        //here we send all data to user event handlers
        _propertyNotificationNotifyEventHandler(this, e);
     }
  }

  public static PropertyNotification GetPropertyNotificationFromPtr(global::System.IntPtr cPtr) {
    PropertyNotification ret = new PropertyNotification(cPtr, false);
   if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }


  public PropertyNotification() : this(NDalicPINVOKE.new_PropertyNotification__SWIG_0(), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public static PropertyNotification DownCast(BaseHandle handle) {
    PropertyNotification ret = new PropertyNotification(NDalicPINVOKE.PropertyNotification_DownCast(BaseHandle.getCPtr(handle)), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public PropertyNotification(PropertyNotification handle) : this(NDalicPINVOKE.new_PropertyNotification__SWIG_1(PropertyNotification.getCPtr(handle)), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public PropertyNotification Assign(PropertyNotification rhs) {
    PropertyNotification ret = new PropertyNotification(NDalicPINVOKE.PropertyNotification_Assign(swigCPtr, PropertyNotification.getCPtr(rhs)), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public PropertyCondition GetCondition() {
    PropertyCondition ret = new PropertyCondition(NDalicPINVOKE.PropertyNotification_GetCondition__SWIG_0(swigCPtr), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Animatable GetTarget() {
    Animatable ret = new Animatable(NDalicPINVOKE.PropertyNotification_GetTarget(swigCPtr), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int GetTargetProperty() {
    int ret = NDalicPINVOKE.PropertyNotification_GetTargetProperty(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void SetNotifyMode(PropertyNotification.NotifyMode mode) {
    NDalicPINVOKE.PropertyNotification_SetNotifyMode(swigCPtr, (int)mode);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public PropertyNotification.NotifyMode GetNotifyMode() {
    PropertyNotification.NotifyMode ret = (PropertyNotification.NotifyMode)NDalicPINVOKE.PropertyNotification_GetNotifyMode(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool GetNotifyResult() {
    bool ret = NDalicPINVOKE.PropertyNotification_GetNotifyResult(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public PropertyNotifySignal NotifySignal() {
    PropertyNotifySignal ret = new PropertyNotifySignal(NDalicPINVOKE.PropertyNotification_NotifySignal(swigCPtr), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public enum NotifyMode {
    Disabled,
    NotifyOnTrue,
    NotifyOnFalse,
    NotifyOnChanged
  }

}

}