/** Copyright (c) 2017 Samsung Electronics Co., Ltd.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/
// This File has been auto-generated by SWIG and then modified using DALi Ruby Scripts
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

public class Model3dView : View {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal Model3dView(global::System.IntPtr cPtr, bool cMemoryOwn) : base(NDalicPINVOKE.Model3dView_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Model3dView obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Model3dView() {
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
          NDalicPINVOKE.delete_Model3dView(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }


  public class Property : global::System.IDisposable {
    private global::System.Runtime.InteropServices.HandleRef swigCPtr;
    protected bool swigCMemOwn;
  
    internal Property(global::System.IntPtr cPtr, bool cMemoryOwn) {
      swigCMemOwn = cMemoryOwn;
      swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
    }
  
    internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Property obj) {
      return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
    }
  
    ~Property() {
      Dispose();
    }
  
    public virtual void Dispose() {
      lock(this) {
        if (swigCPtr.Handle != global::System.IntPtr.Zero) {
          if (swigCMemOwn) {
            swigCMemOwn = false;
            NDalicPINVOKE.delete_Model3dView_Property(swigCPtr);
          }
          swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
        }
        global::System.GC.SuppressFinalize(this);
      }
    }
  
    public Property() : this(NDalicPINVOKE.new_Model3dView_Property(), true) {
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    }
  
    public static readonly int GEOMETRY_URL = NDalicPINVOKE.Model3dView_Property_GEOMETRY_URL_get();
    public static readonly int MATERIAL_URL = NDalicPINVOKE.Model3dView_Property_MATERIAL_URL_get();
    public static readonly int IMAGES_URL = NDalicPINVOKE.Model3dView_Property_IMAGES_URL_get();
    public static readonly int ILLUMINATION_TYPE = NDalicPINVOKE.Model3dView_Property_ILLUMINATION_TYPE_get();
    public static readonly int TEXTURE0_URL = NDalicPINVOKE.Model3dView_Property_TEXTURE0_URL_get();
    public static readonly int TEXTURE1_URL = NDalicPINVOKE.Model3dView_Property_TEXTURE1_URL_get();
    public static readonly int TEXTURE2_URL = NDalicPINVOKE.Model3dView_Property_TEXTURE2_URL_get();
    public static readonly int LIGHT_POSITION = NDalicPINVOKE.Model3dView_Property_LIGHT_POSITION_get();
  
  }

  public Model3dView () : this (NDalicPINVOKE.Model3dView_New__SWIG_0(), true) {
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();

  }
  public Model3dView (string objUrl, string mtlUrl, string imagesUrl) : this (NDalicPINVOKE.Model3dView_New__SWIG_1(objUrl, mtlUrl, imagesUrl), true) {
      if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();

  }
  public Model3dView(Model3dView model3dView) : this(NDalicPINVOKE.new_Model3dView__SWIG_1(Model3dView.getCPtr(model3dView)), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public Model3dView Assign(Model3dView model3dView) {
    Model3dView ret = new Model3dView(NDalicPINVOKE.Model3dView_Assign(swigCPtr, Model3dView.getCPtr(model3dView)), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public new static Model3dView DownCast(BaseHandle handle) {
    Model3dView ret = new Model3dView(NDalicPINVOKE.Model3dView_DownCast(BaseHandle.getCPtr(handle)), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public enum PropertyRange {
    PROPERTY_START_INDEX = PropertyRanges.PROPERTY_REGISTRATION_START_INDEX,
    PROPERTY_END_INDEX = View.PropertyRange.PROPERTY_START_INDEX+1000,
    ANIMATABLE_PROPERTY_START_INDEX = PropertyRanges.ANIMATABLE_PROPERTY_REGISTRATION_START_INDEX,
    ANIMATABLE_PROPERTY_END_INDEX = PropertyRanges.ANIMATABLE_PROPERTY_REGISTRATION_START_INDEX+1000
  }

  public enum IluminationTypeEnum {
    DIFFUSE,
    DIFFUSE_WITH_TEXTURE,
    DIFFUSE_WITH_NORMAL_MAP
  }

  public string GeometryUrl
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.GEOMETRY_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.GEOMETRY_URL, new Dali.Property.Value( value ) );
    }
  }
  public string MaterialUrl
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.MATERIAL_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.MATERIAL_URL, new Dali.Property.Value( value ) );
    }
  }
  public string ImagesUrl
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.IMAGES_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.IMAGES_URL, new Dali.Property.Value( value ) );
    }
  }
  public int IlluminationType
  {
    get
    {
      int temp = 0;
      GetProperty( Model3dView.Property.ILLUMINATION_TYPE).Get( ref temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.ILLUMINATION_TYPE, new Dali.Property.Value( value ) );
    }
  }
  public string Texture0Url
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.TEXTURE0_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.TEXTURE0_URL, new Dali.Property.Value( value ) );
    }
  }
  public string Texture1Url
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.TEXTURE1_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.TEXTURE1_URL, new Dali.Property.Value( value ) );
    }
  }
  public string Texture2Url
  {
    get
    {
      string temp;
      GetProperty( Model3dView.Property.TEXTURE2_URL).Get( out temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.TEXTURE2_URL, new Dali.Property.Value( value ) );
    }
  }
  public Vector3 LightPosition
  {
    get
    {
      Vector3 temp = new Vector3(0.0f,0.0f,0.0f);
      GetProperty( Model3dView.Property.LIGHT_POSITION).Get(  temp );
      return temp;
    }
    set
    {
      SetProperty( Model3dView.Property.LIGHT_POSITION, new Dali.Property.Value( value ) );
    }
  }

}

}
