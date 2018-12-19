let component = ReasonReact.statelessComponent("Resume");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  px-16
`)
|}];

let resumeStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~height="100%",
    ~width="100%",
    ~fontSize="10",
    ~color="grey",
    (),
  );

let headerSectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~height="10%",
    ~width="100%",
    ~borderBottomWidth="2",
    ~borderColor="gold",
    (),
  );

let contentSectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~height="90%",
    ~width="100%",
    (),
  );

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let projects = props##data##projects##edges;

    <ReactPdfDocument>
      <ReactPdfPage size="A4">
        <ReactPdfView style=resumeStyle>
          <ReactPdfView style=headerSectionStyle>
            <ResumeHeader/>
          </ReactPdfView>
          <ReactPdfView style=contentSectionStyle>
            <ResumeSection title="Personal Profile">
              <ReactPdfText>{ReasonReact.string(Helper_Me.about)}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Work Experience">
              <ReactPdfText>{ReasonReact.string("Content")}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Key Skills">
              <ReactPdfText>{ReasonReact.string("Content")}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Education">
              <ReactPdfText>{ReasonReact.string("Content")}</ReactPdfText>
            </ResumeSection>
          </ReactPdfView>
          /* {
            projects
            |> Belt.List.fromArray
            |> Belt.List.map(_, (edge) => {
                <ReactPdfView key=edge##node##id style=sectionStyle>
                  <ReactPdfText>
                    {ReasonReact.string(edge##node##frontmatter##title)}
                  </ReactPdfText>
                </ReactPdfView>
              })
            |> Belt.List.toArray
            |> ReasonReact.array
          } */
          
        </ReactPdfView>
      </ReactPdfPage>
    </ReactPdfDocument>;
  }
};