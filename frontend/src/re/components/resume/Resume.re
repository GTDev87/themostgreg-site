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
    ~height="100",
    ~width="100%",
    ~borderBottomWidth="2",
    ~borderColor="gold",
    (),
  );

let contentSectionStyle =
  ReactPdfStyleSheet.createStyleSheet(
    /* ~height="90%", */
    ~width="100%",
    (),
  );

let hasJobType = (projects, jobTypeName) =>
  projects##edges
  |> Belt.List.fromArray
  |> Belt.List.keep(_, edge => {
      (
        edge##node##frontmatter##jobType
        |> Belt.List.fromArray
        |> Belt.List.keep(_, (jobType) => jobType == jobTypeName)
        |> Belt.List.length
   ) > 0
  })
  |> Belt.List.map(_, edge => edge##node);

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let works = hasJobType(props##data##projects, "job");
    let contractWorks = hasJobType(props##data##projects, "contract");
    <ReactPdfDocument>
      <ReactPdfPage size="A4">
        <ReactPdfView style=resumeStyle>
          <ReactPdfView style=headerSectionStyle>
            <ResumeHeader/>
          </ReactPdfView>
          <ReactPdfView style=contentSectionStyle>
            <ResumeSection title="Personal Profile">
              <ReactPdfText key="profile">{ReasonReact.string(Helper_Me.resumeAbout)}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Work Experience">
              <ResumeWorkExperience key="work" works=works />
            </ResumeSection>
            <ResumeSection title="Contract Work">
              <ResumeWorkExperience key="contracts" works=contractWorks />
            </ResumeSection>
            <ResumeSection title="Key Skills">
              <ReactPdfText key="key skills">{ReasonReact.string("Content")}</ReactPdfText>
            </ResumeSection>
            <ResumeSection title="Education">
              <ReactPdfText key="education">{ReasonReact.string("Content")}</ReactPdfText>
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