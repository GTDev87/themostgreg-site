[@bs.module "react-feather/dist/icons/calendar"]
external comp: ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );