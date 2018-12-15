import React from 'react';
import WithSpectacle from "./spectacle"

export default class SpectacleSlides extends React.Component {
  render() {
    return (
      <WithSpectacle
        render={({ Deck, MarkdownSlides }) =>
          <Deck theme={this.props.theme}>
            {MarkdownSlides(this.props.markdown).slice(1)}
          </Deck>
        }
      />
    );
  }
}
