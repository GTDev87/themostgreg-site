let component = ReasonReact.statelessComponent("CircleInfo");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

type sizes =
  | MD
  | LG;

let iconCircleClass = size =>
  switch (size) {
  | MD =>
    %bs.raw {| css(tw`
      rounded-full
      h-32
      w-32
      flex
      items-center
      justify-center
      bg-teal
      mb-4
    `)
    |}
  | LG =>
    %bs.raw
    {| css(tw`
      rounded-full
      h-64
      w-64
      flex
      items-center
      justify-center
      bg-teal
      mb-4
    `)
    |}
  };

let circleInfoClass = [%bs.raw {| css(tw`
  flex
  justify-center
  flex-col
  m-8
  text-center
`)|}
];

let labelClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  text-xl
  text-grey-darkest
  font-bold
`)
|}
];

let centerWrapper = [%bs.raw {| css(tw`
  flex
  justify-center
`)
|}];

let hiddenOpacity = [%bs.raw {| css(tw` opacity-0 `)|}];

let classTransitionIn = (waypointEntered, className) => {
  let hiddenOpacity = [%bs.raw {| css(tw` opacity-0 `)|}];

  waypointEntered ? className : hiddenOpacity;
};

let circleInfoTransitionInClasses = "transition transition-timing-ease-in transition-slower";

let make = (~size=MD, ~comp, ~label, ~copy, _children) => {
  ...component,
  render: _self =>
    <WaypointGenerator wayKey=label>
      ...{(~waypointEntered) => {
        <div className=cx(circleInfoClass, classTransitionIn(waypointEntered, circleInfoTransitionInClasses))>
          <div>
            <div className=centerWrapper>
              <div className={iconCircleClass(size)}> comp </div>
            </div>
            <div className=centerWrapper>
              <div className=labelClass> {ReasonReact.string(label)} </div>
            </div>
            <div className=centerWrapper>
              <div> {ReasonReact.string(copy)} </div>
            </div>
          </div>
        </div>
      }}
    </WaypointGenerator>
};