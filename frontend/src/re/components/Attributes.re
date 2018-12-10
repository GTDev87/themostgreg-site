let component = ReasonReact.statelessComponent("Attributes");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let attributesClass = [%bs.raw {| css(tw`
  flex
  justify-center
`)
|}];

let barsClass = [%bs.raw {| css(tw`
  self-center
  w-full
`)
|}];

let attributesAttributeClass = [%bs.raw {| css(tw`
  mb-6
`)
|}];

type attributes = list(Attribute.attribute);

let attributes: attributes = [
  {label: "Business Logic", percentage: 90.},
  {label: "ReasonML", percentage: 50.},
  {label: "React", percentage: 90.},
  {label: "Css", percentage: 50.},
  {label: "Iteration Speed", percentage: 80.},
  {label: "Elixir", percentage: 60.},
  {label: "Culture", percentage: 90.},
  {label: "Enthusiasm", percentage: 100.},
  {label: "Bouldering", percentage: 70.},
];

let classTransitionIn = (waypointEntered, className) => {
  let hiddenOpacity = [%bs.raw {| css(tw` opacity-0 `)|}];

  waypointEntered ? className : hiddenOpacity;
};

let circleInfoTransitionInClasses = "transition transition-timing-ease-in transition-slower";

let make = _children => {
  ...component,
  render: _self =>
    <div className=attributesClass>
      <WaypointGenerator wayKey="attributes">
        ...{(~waypointEntered) => {
          <div className=cx(barsClass, classTransitionIn(waypointEntered, circleInfoTransitionInClasses))>
            {
              attributes
              |> Belt.List.map(_, (attribute: Attribute.attribute) =>
                  <div className=attributesAttributeClass key={attribute.label}>
                    <Attribute attribute />
                  </div>
                )
              |> Utils.ReasonReact.listToReactArray
            }
          </div>
        }}
      </WaypointGenerator>
    </div>,
};