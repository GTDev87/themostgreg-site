let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  py-16
  px-16
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <Section title="About"> <Traits /> <WhoAmI /> </Section>
    </div>,
};