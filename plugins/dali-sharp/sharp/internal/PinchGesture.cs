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

public class PinchGesture : Gesture {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal PinchGesture(global::System.IntPtr cPtr, bool cMemoryOwn) : base(NDalicPINVOKE.PinchGesture_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(PinchGesture obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~PinchGesture() {
    DisposeQueue.Instance.Add(this);
  }

  public override void Dispose() {
    if (!Stage.IsInstalled()) {
      DisposeQueue.Instance.Add(this);
      return;
    }

    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          NDalicPINVOKE.delete_PinchGesture(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }


  public static PinchGesture GetPinchGestureFromPtr(global::System.IntPtr cPtr) {
    PinchGesture ret = new PinchGesture(cPtr, false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public float Scale
  {
    get
    {
      return scale;
    }
  }

  public float Speed
  {
    get
    {
      return speed;
    }
  }

  public Vector2 ScreenCenterPoint
  {
    get
    {
      return screenCenterPoint;
    }
  }

  public Vector2 LocalCenterPoint
  {
    get
    {
      return localCenterPoint;
    }
  }

  public PinchGesture(Gesture.StateType state) : this(NDalicPINVOKE.new_PinchGesture__SWIG_0((int)state), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public PinchGesture(PinchGesture rhs) : this(NDalicPINVOKE.new_PinchGesture__SWIG_1(PinchGesture.getCPtr(rhs)), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public PinchGesture Assign(PinchGesture rhs) {
    PinchGesture ret = new PinchGesture(NDalicPINVOKE.PinchGesture_Assign(swigCPtr, PinchGesture.getCPtr(rhs)), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private float scale {
    set {
      NDalicPINVOKE.PinchGesture_scale_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      float ret = NDalicPINVOKE.PinchGesture_scale_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private float speed {
    set {
      NDalicPINVOKE.PinchGesture_speed_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      float ret = NDalicPINVOKE.PinchGesture_speed_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private Vector2 screenCenterPoint {
    set {
      NDalicPINVOKE.PinchGesture_screenCenterPoint_set(swigCPtr, Vector2.getCPtr(value));
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = NDalicPINVOKE.PinchGesture_screenCenterPoint_get(swigCPtr);
      Vector2 ret = (cPtr == global::System.IntPtr.Zero) ? null : new Vector2(cPtr, false);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private Vector2 localCenterPoint {
    set {
      NDalicPINVOKE.PinchGesture_localCenterPoint_set(swigCPtr, Vector2.getCPtr(value));
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = NDalicPINVOKE.PinchGesture_localCenterPoint_get(swigCPtr);
      Vector2 ret = (cPtr == global::System.IntPtr.Zero) ? null : new Vector2(cPtr, false);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

}

}
