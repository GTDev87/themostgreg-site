let component = ReasonReact.statelessComponent("TestComponent");

let make = _children => {
  ...component,
  render: _self =>
    <div> {ReasonReact.string("HELLO FRO REASON REACT")} </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make([|
      /* ~server=(
           jsProps##server
           |> Js.undefinedToOption
           |> Belt.Option.getWithDefault(_, false)
         ), */
      /* ~initialUrl=Js.undefinedToOption(jsProps##initialUrl), */
    |])
  );