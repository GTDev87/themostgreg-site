[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "View";

/* Note: these do not take className */
let make = (~style: option(ReactDOMRe.style)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "style":
        style
        |> Belt.Option.map(_, ReactPdfStyleSheet.createStyleSheet)
        |> Js.Nullable.fromOption,
    },
    children,
  );