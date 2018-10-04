let component = ReasonReact.statelessComponent("Attribute");

let css = Css.css;
let tw = Css.tw;

type attribute = {
  label: string,
  percentage: float,
};

let attributeClass = [%bs.raw {| css(tw`
`)
|}];

let make = (~attribute, _children) => {
  ...component,
  render: _self => <div className=attributeClass />,
};