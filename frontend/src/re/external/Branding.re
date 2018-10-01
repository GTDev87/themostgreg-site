[@bs.module "@react-website-themes/default/components/Branding"]
external comp: ReasonReact.reactClass = "default";

let make = (~title, ~subTitle, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={"title": title, "subTitle": subTitle},
    children,
  );