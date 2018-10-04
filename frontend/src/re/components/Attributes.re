let component = ReasonReact.statelessComponent("Attributes");

let css = Css.css;
let tw = Css.tw;

let attributesClass = [%bs.raw {| css(tw`
`)
|}];

type attributes = list(Attribute.attribute);

let attributes: attributes = [
  {label: "ReasonMl", percentage: 50.},
  {label: "React", percentage: 90.},
  {label: "Css", percentage: 50.},
  {label: "Elixir", percentage: 60.},
];

let make = _children => {
  ...component,
  render: _self =>
    <div className=attributesClass>
      {
        attributes
        |> Belt.List.map(_, (attribute: Attribute.attribute) =>
             <div> <Attribute key={attribute.label} attribute /> </div>
           )
        |> Utils.ReasonReact.listToReactArray
      }
    </div>,
};