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

public class Wheel : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Wheel(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Wheel obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Wheel() {
    DisposeQueue.Instance.Add(this);
  }

  public virtual void Dispose() {
    if (!Stage.IsInstalled()) {
      DisposeQueue.Instance.Add(this);
      return;
    }

    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          NDalicPINVOKE.delete_Wheel(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }


  public static Wheel GetWheelFromPtr(global::System.IntPtr cPtr) {
    Wheel ret = new Wheel(cPtr, false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Wheel.WheelType Type
  {
    get
    {
      return type;
    }
  }

  public int Direction
  {
    get
    {
      return direction;
    }
  }

  public uint Modifiers
  {
    get
    {
      return modifiers;
    }
  }

  public Vector2 Point
  {
    get
    {
      return point;
    }
  }

  public int Z
  {
    get
    {
      return z;
    }
  }

  public uint TimeStamp
  {
    get
    {
      return timeStamp;
    }
  }

  public Wheel() : this(NDalicPINVOKE.new_Wheel__SWIG_0(), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public Wheel(Wheel.WheelType type, int direction, uint modifiers, Vector2 point, int z, uint timeStamp) : this(NDalicPINVOKE.new_Wheel__SWIG_1((int)type, direction, modifiers, Vector2.getCPtr(point), z, timeStamp), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool IsShiftModifier() {
    bool ret = NDalicPINVOKE.Wheel_IsShiftModifier(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool IsCtrlModifier() {
    bool ret = NDalicPINVOKE.Wheel_IsCtrlModifier(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool IsAltModifier() {
    bool ret = NDalicPINVOKE.Wheel_IsAltModifier(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private Wheel.WheelType type {
    set {
      NDalicPINVOKE.Wheel_type_set(swigCPtr, (int)value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      Wheel.WheelType ret = (Wheel.WheelType)NDalicPINVOKE.Wheel_type_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private int direction {
    set {
      NDalicPINVOKE.Wheel_direction_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = NDalicPINVOKE.Wheel_direction_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private uint modifiers {
    set {
      NDalicPINVOKE.Wheel_modifiers_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      uint ret = NDalicPINVOKE.Wheel_modifiers_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private Vector2 point {
    set {
      NDalicPINVOKE.Wheel_point_set(swigCPtr, Vector2.getCPtr(value));
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = NDalicPINVOKE.Wheel_point_get(swigCPtr);
      Vector2 ret = (cPtr == global::System.IntPtr.Zero) ? null : new Vector2(cPtr, false);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private int z {
    set {
      NDalicPINVOKE.Wheel_z_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = NDalicPINVOKE.Wheel_z_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  private uint timeStamp {
    set {
      NDalicPINVOKE.Wheel_timeStamp_set(swigCPtr, value);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      uint ret = NDalicPINVOKE.Wheel_timeStamp_get(swigCPtr);
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public enum WheelType {
    MOUSE_WHEEL,
    CUSTOM_WHEEL
  }

}

}
