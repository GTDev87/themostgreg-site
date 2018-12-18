[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];
[%bs.raw {|require('tailwindcss/tailwind.css')|}];

let css = Css.css;
let tw = Css.tw;

let viwerClassName = [%bs.raw
  {| css(tw`
    w-screen
    h-screen
  `) |}
];

let sectionStyle =
  ReactDOMRe.Style.make(
    ~backgroundColor="green",
    (),
  );

let component = ReasonReact.statelessComponent("Page_Resume");

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: self => {
    <ReactPdfViewer className=viwerClassName>
      <ReactPdfDocument>
        <ReactPdfPage size=("A4")>
          <ReactPdfView style=sectionStyle>
            <ReactPdfText>{ReasonReact.string("Section #1")}</ReactPdfText>
          </ReactPdfView>
          <ReactPdfView style=sectionStyle>
            <ReactPdfText>{ReasonReact.string("Section #2")}</ReactPdfText>
          </ReactPdfView>
        </ReactPdfPage>
      </ReactPdfDocument>
    </ReactPdfViewer>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );