let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  py-16
  px-16
`)
|}];

let aboutText = [%bs.raw
  {| css(tw`
  text-3xl
  w-full
  flex
  justify-center
  underline
`)
|}
];

let make = _children => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <div className=aboutText> {ReasonReact.string("About")} </div>
      <Traits />
      <WhoAmI />
    </div>,
};