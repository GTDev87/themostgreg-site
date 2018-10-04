let component = ReasonReact.statelessComponent("WhoAmI");

let css = Css.css;
let tw = Css.tw;

let imageSection = [%bs.raw {| css(tw`
  md:w-1/2
  `)
  |}];

let attributeSection = [%bs.raw {| css(tw`
  md:w-1/2
  `)
  |}];

let whoAmIClass = [%bs.raw {| css(tw`
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=whoAmIClass>
      <div className=imageSection />
      <div className=attributeSection />
    </div>,
};