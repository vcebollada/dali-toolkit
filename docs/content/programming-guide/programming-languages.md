<!--
/**-->

# Programming Languages {#programming-languages}

DALi applications can be written in several different programming languages.

## C++ {#c-plus-plus}

~~~{.cpp}
Dali::Actor actor = Dali::Actor::New();
actor.SetParentOrigin( Dali::ParentOrigin::CENTER );
actor.SetAnchorPoint( Dali::AnchorPoint::CENTER );
Dali::Stage::GetCurrent().Add( actor );
...
bool OnPressed( Dali::Actor, const TouchData& touch )
{
  Dali::Animation anim = Dali::Animation::New( 1.5f );
  anim.AnimateTo( Property( actor, Actor::Property::POSITION ), Vector3( 200, -100, 0 ), AlphaFunctions::Bounce );
  anim.play();
  return true; // consume the touch event
}
...
actor.TouchSignal().Connect( &OnPressed );
~~~

## JSON {#json-support}

~~~{.json}
{
 "animations":
  {
    "move":
    {
      "duration": 1.5,
      "properties":
      [
        {
          "actor":"image",
          "property":"position",
          "value":[200,-100,0],
          "alphaFunction": "BOUNCE"
        }
      ]
    }
  },
  "stage":
  [
    {
      "name":"image",
      "type":"Actor",
      "anchorPoint": "CENTER",
      "parentOrigin": "CENTER",
      "signals" :
      [
        { "name" : "touch", "action": "play", "animation": "move" }
      ]
    }
  ]
}
~~~
