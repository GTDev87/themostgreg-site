[@bs.module "../../../../../src/spectacleSlides"]
external comp: ReasonReact.reactClass = "default";

let make = (
  ~theme: Spectacle.theme,
  ~markdown: string,
  _children
) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=comp,
    ~props={
      "theme": theme,
      "markdown": markdown,
    },
    _children,
  );
};