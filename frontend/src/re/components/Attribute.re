let component = ReasonReact.statelessComponent("Attribute");

let css = Css.css;
let tw = Css.tw;

type attribute = {
  label: string,
  percentage: float,
};

let attributeClass = [%bs.raw {| css(tw`
  flex
  text-white
`)
|}];

let labelClass = [%bs.raw {| css(tw`
  w-1/4
  h-6
  bg-teal
  `)
  |}];

let percentageClass = [%bs.raw {| css(tw`
  w-3/4
  h-6
  flex
  `)
  |}];

let colorBarPercentageClass = [%bs.raw {| css(tw`
  bg-teal-dark
  `)
  |}];

let remainingPercentageClass = [%bs.raw {| css(tw`
  bg-grey-light
  `)
  |}];

let labelTextClass = [%bs.raw {| css(tw`
  ml-2
  `)
  |}];

let remainingPercentageText = [%bs.raw
  {| css(tw`
  text-grey-darkest
  float-right
  mr-2
  `)
  |}
];

let colorBarPercentageStyle = percentage =>
  ReactDOMRe.Style.make(~width=string_of_float(percentage) ++ "%", ());

let remainingPercentageStyle = percentage =>
  ReactDOMRe.Style.make(
    ~width=string_of_float(100.0 -. percentage) ++ "%",
    (),
  );

let make = (~attribute, _children) => {
  ...component,
  render: _self =>
    <div className=attributeClass>
      <div className=labelClass>
        <div className=labelTextClass>
          {ReasonReact.string(attribute.label)}
        </div>
      </div>
      <div className=percentageClass>
        <div
          style={colorBarPercentageStyle(attribute.percentage)}
          className=colorBarPercentageClass
        />
        <div
          style={remainingPercentageStyle(attribute.percentage)}
          className=remainingPercentageClass>
          <div className=remainingPercentageText>
            {
              ReasonReact.string(
                (attribute.percentage |> string_of_float) ++ "%",
              )
            }
          </div>
        </div>
      </div>
    </div>,
};