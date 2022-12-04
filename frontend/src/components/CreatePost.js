import { Cookies, useCookies } from 'react-cookie';
import React from "react";

// post:owner:title:description:type
const CreatePost = () =>{

  const socket =  new WebSocket('ws://127.0.0.1:2236');
  const [cookies, setCookie] = useCookies(['user']);

  function inputToString(document) {
    return "post:"+cookies.Name+":"
        +document.getElementById("title").value+":"
        +document.getElementById("post").value+":"
        +document.getElementById("type").value;
  }

  return (
    <div className="createPostPage">
      <div className="cpContainer">
        <h1 style={{color:"white"}}>Create A Post by {cookies.Name}</h1>
          <label style={{color:"white"}}> Title:</label>
          <input id="title"
            placeholder="Title..."
          />
        </div>
          <label style={{color:"white"}}> Post:</label>
          <textarea id="post"
            placeholder="Post..."
          />
        <div className="inputGp">
          <label style={{color:"white"}}> Category:</label>
          <textarea id="type"
            placeholder="Input number:
            0: Nightlife
            1: Special Event
            2: House Party
            3: Campus Event"
          />
        </div>
        <button type="submit" onClick = {() => socket.send(inputToString(document))}>Post</button>


    </div>
  );
}

export default CreatePost;