import './App.css';
import Navbar from './components/Navbar';
import Home from './components/Home';
import SignIn from './components/SignIn';
import { BrowserRouter, Routes, Route } from "react-router-dom";

function App() {
  return (
    <div className="App">
      <Navbar></Navbar>
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Home></Home>}></Route>
          <Route path="/signIn" element={<SignIn></SignIn>}></Route>
        </Routes>

      </BrowserRouter>


      

    </div>
  );
}

export default App;

