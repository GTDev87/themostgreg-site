let component = ReasonReact.statelessComponent("Intro");

let css = Css.css;
let tw = Css.tw;
let introClass = [%bs.raw
  {| css(tw`
    flex
    justify-center
    w-full
    h-screen
    bg-grey-darkest
  `) |}
];

let centerClass = [%bs.raw {| css(tw`
  self-center
  `)
|}];

let textClass = [%bs.raw {| css(tw`
  text-white
  text-5xl
  pb-2
  `)
|}];

let buttonClass = [%bs.raw
  {| css(tw`
    bg-grey-darkest
    text-white
    border-solid
    text-xl
    py-2
    px-4
    hover:bg-teal
    hover:text-white
    border-2
    no-underline
  `)
|}
];

let buttonWrapperClass = [%bs.raw {| css(tw`
  flex
  justify-center
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=introClass>
      <div className=centerClass>
        <div className=textClass> {ReasonReact.string("The Most Greg")} </div>
        <div className=buttonWrapperClass>
          <a href="#projects" className=buttonClass>
            {ReasonReact.string("View my work")}
          </a>
        </div>
      </div>
    </div>,
};