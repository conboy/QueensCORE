import { Cookies, useCookies } from 'react-cookie';

// post:owner:title:description:type
const CreatePost = () =>{

  const ws =  new WebSocket('ws://127.0.0.1:2236');
  const [cookies, setCookie] = useCookies(['user']);



  return (
    <div className="createPostPage">
      <div className="cpContainer">
        <h1 style={{color:"white"}}>Create A Post by {cookies.Name}</h1>
        <div className="inputGp">
          <label style={{color:"white"}}> Title:</label>
          <input
            placeholder="Title..."
            // onChange={(event) => {
            //   setTitle(event.target.value);
            // }}
          />
        </div>
        <div className="inputGp">
          <label style={{color:"white"}}> Post:</label>
          <textarea
            placeholder="Post..."
            // onChange={(event) => {
            //   setPostText(event.target.value);
            // }}
          />
        </div>
        <div className="inputGp">
          <label style={{color:"white"}}> Category:</label>
          <textarea
            placeholder="Input number:
            0: Nightlife
            1: Special Event
            2: House Party
            3: Campus Event"
            // onChange={(event) => {
            //   setPostText(event.target.value);
            // }}
          />
        </div>
        <button /*{onClick={createPost}}*/> Submit Post</button>
      </div>
    </div>
  );
}

export default CreatePost;