type t;
type styleSheet;
[@bs.module "@react-pdf/renderer"] external styleSheet: t = "StyleSheet";
[@bs.send] external create: (t, ReactDOMRe.style) => styleSheet = "create";

let createStyleSheet = (styles: ReactDOMRe.style) => create(styleSheet, styles);


