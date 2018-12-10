[@bs.module "gatsby-mdx/mdx-renderer"]
external comp: ReasonReact.reactClass = "default";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props=Js.Obj.empty(),
    children,
  );