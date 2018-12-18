[@bs.module "@react-pdf/renderer"]
external comp: ReasonReact.reactClass = "Page";

let make = (~size: string, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "size": size
    },
    children,
  );