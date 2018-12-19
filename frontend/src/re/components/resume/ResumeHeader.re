let component = ReasonReact.statelessComponent("ResumeHeader");

let headerStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-between",
    ~height="100%",
    ~width="100%",
    ~paddingTop="3%",
    ~paddingBottom="3%",
    ~paddingLeft="4%",
    ~paddingRight="4%",
    (),
  );

let nameSectionWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    (),
  );

let nameTextStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="20",
    ~fontWeight="900",
    (),
  );

let titleTextStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="12",
    ~fontWeight="800",
    (),
  );

let contactTextStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~fontSize="8",
    ~marginBottom="3%",
    (),
  );

let imageStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~width="100%",
    (),
  );

let contactSectionWrapperStyle = ReactPdfStyleSheet.createStyleSheet(
  ~height="100%",
  ~width="20%",
  (),
);

let imageWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~marginRight="5%",
    ~display="flex",
    ~justifyContent="center",
    ~alignItems="center",
    (),
  );

let titleWrapperStyle =
  ReactPdfStyleSheet.createStyleSheet(
    ~height="100%",
    ~width="80%",
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-between",
    (),
  );

let make = (_children) => {
  ...component,
  render: _self => {
    <ReactPdfView style=headerStyle>
      <ReactPdfView style=titleWrapperStyle>
        <ReactPdfView style=imageWrapperStyle>
          <ReactPdfImage style=imageStyle src=Helper_Me.gregImageCircle />
        </ReactPdfView>
        <ReactPdfView style=nameSectionWrapperStyle>
          <ReactPdfText style=nameTextStyle>{ReasonReact.string(Helper_Me.name)}</ReactPdfText>
          <ReactPdfText style=titleTextStyle>{ReasonReact.string("Developer/Consultant")}</ReactPdfText>
        </ReactPdfView>
      </ReactPdfView>
      <ReactPdfView style=contactSectionWrapperStyle>
        <ReactPdfText style=contactTextStyle>{ReasonReact.string("e: " ++ Helper_Me.email)}</ReactPdfText>
        <ReactPdfText style=contactTextStyle>{ReasonReact.string("w: " ++ Helper_Me.site)}</ReactPdfText>
        <ReactPdfText style=contactTextStyle>{ReasonReact.string("m: " ++ Helper_Me.phone)}</ReactPdfText>
      </ReactPdfView>
    </ReactPdfView>
  }
};