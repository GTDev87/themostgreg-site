let component = ReasonReact.statelessComponent("ResumeWorkProject");
let resumeWorkExperienceTitleStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="14",
    (),
  );

let resumeWorkExperienceTimeWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~marginBottom="5",
    (),
  );

let resumeWorkExperienceTimeStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="8",
    (),
  );

let make = (~work: PagePropType.nodeType, _children) => {
  ...component,
  render: (_self) => {
    <ReactPdfView>
      <ReactPdfView>
        <ReactPdfText style=resumeWorkExperienceTitleStyle>
          {ReasonReact.string(work##frontmatter##title)}
        </ReactPdfText>
      </ReactPdfView>
      <ReactPdfView style=resumeWorkExperienceTimeWrapperStyle>
        <ReactPdfText style=resumeWorkExperienceTimeStyle>
          /* {ReasonReact.string(work##frontmatter##startTime ++ " - "++ work##frontmatter##endTime)} */
        </ReactPdfText>
      </ReactPdfView>
      <ReactPdfView>
        <ReactPdfText>{ReasonReact.string(work##excerpt)}</ReactPdfText>
      </ReactPdfView>
    </ReactPdfView>
  }
};