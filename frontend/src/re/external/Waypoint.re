[@bs.module "react-waypoint"]
external comp: ReasonReact.reactClass = "default";

let make = (~onEnter, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"onEnter": onEnter},
    children,
  );
