[@bs.module "@react-website-themes/default/components/Footer"]
external comp: ReasonReact.reactClass = "default";

let make = (~links, ~copyright, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "links": Js.Nullable.fromOption(links),
      "copyright": Js.Nullable.fromOption(copyright),
    },
    children,
  );