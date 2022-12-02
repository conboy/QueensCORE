const CreatePost = () =>{
  return (
    <div className="createPostPage">
      <div className="cpContainer">
        <h1>Create A Post</h1>
        <div className="inputGp">
          <label> Title:</label>
          <input
            placeholder="Title..."
            // onChange={(event) => {
            //   setTitle(event.target.value);
            // }}
          />
        </div>
        <div className="inputGp">
          <label> Post:</label>
          <textarea
            placeholder="Post..."
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