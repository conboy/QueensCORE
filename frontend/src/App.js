import './App.css';
import Navbar from './components/Navbar';
import Home from './components/Home';
import SignIn from './components/SignIn';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import CreatePost from './components/CreatePost';
import Profile from './components/Profile';

function App() {
  return (
    <div className="App">
      <Navbar></Navbar>
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Home></Home>}></Route>
          <Route path="/signIn" element={<SignIn></SignIn>}></Route>
          <Route path="/CreatePost" element={<CreatePost></CreatePost>}></Route>
          <Route path="/Profile" element={<Profile></Profile>}></Route>
        </Routes>

      </BrowserRouter>

      

    </div>
  );
}

export default App;

