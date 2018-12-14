[@bs.module "spectacle"]
external comp: ReasonReact.reactClass = "Deck";

let make = (children: array(ReasonReact.reactElement)) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );
};