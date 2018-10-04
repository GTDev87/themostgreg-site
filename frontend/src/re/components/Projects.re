let component = ReasonReact.statelessComponent("Projects");

let css = Css.css;
let tw = Css.tw;

let projectsClass = [%bs.raw {| css(tw`
  py-16
  px-16
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=projectsClass> <Section title="Projects" /> </div>,
};