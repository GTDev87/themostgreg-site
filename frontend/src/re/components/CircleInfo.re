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
    %bs.raw
    {| css(tw`
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

let circleInfoClass =
  cx(
    [%bs.raw
      {| css(tw`
        flex
        justify-center
        flex-col
        mx-12
        text-center
        mb-4
        `)
      |}
    ],
    "transition",
  );

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

let make = (~size=MD, ~comp, ~label, ~copy, _children) => {
  ...component,
  render: _self =>
    <div className=circleInfoClass>
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
    </div>,
};