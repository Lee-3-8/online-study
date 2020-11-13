import React, { Component} from 'react';

class App extends Component {
  render(){
    const name = 'react';
    const style = {
      backgroundColor : 'black',
      padding : '16px',
      color : 'white',
      fontSize : '12px'
    };
    return(
      <React.Fragment>
        <div style = {style}>
          Hello {name}!
        </div>
        <div>
          Bye
        </div>
      </React.Fragment>
      );
  }
}

export default App;
