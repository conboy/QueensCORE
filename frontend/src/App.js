import logo from './logo.svg';
import './App.css';
import Navbar from './components/Navbar';
import Home from './components/Home';
import SignIn from './components/SignIn';

import ReactDOM from "react-dom/client";

function App() {
  return (
    <div className="App">
      <Navbar></Navbar>
      {/* <SignIn></SignIn> */}
      <Home></Home>
      

    </div>
  );
}

export default App;
