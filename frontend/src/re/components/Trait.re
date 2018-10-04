let component = ReasonReact.statelessComponent("Trait");

let css = Css.css;
let tw = Css.tw;

type trait = {
  label: string,
  copy: string,
  icon: ReasonReact.reactClass,
};

let iconCircleClass = [%bs.raw
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
];

let traitClass = [%bs.raw
  {| css(tw`
  flex
  justify-center
  flex-col
  m-12
  text-center
`)
|}
];

let iconClass = [%bs.raw {| css(tw`
  text-white
`)
|}];

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

let make = (~trait: trait, _children) => {
  ...component,
  render: _self =>
    <div className=traitClass>
      <div>
        <div className=centerWrapper>
          <div className=iconCircleClass>
            <Icon comp={trait.icon} className=iconClass />
          </div>
        </div>
        <div className=centerWrapper>
          <div className=labelClass> {ReasonReact.string(trait.label)} </div>
        </div>
        <div className=centerWrapper>
          <div> {ReasonReact.string(trait.copy)} </div>
        </div>
      </div>
    </div>,
};