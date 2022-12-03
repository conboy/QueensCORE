import { getAllByPlaceholderText } from '@testing-library/react';
import {useState } from 'react';
import CreatePost from './CreatePost';
import { BrowserRouter as Router,Link } from 'react-router-dom';

var usersData = {
  total: 3,
  data: [
    { votes: 321, postTitle: "QMIND", username: "floppydiskette", body: "Queens Ai design club"},
    { votes: 163, postTitle: "QUANTT", username: "siliconeidolon", body: "A quantatative trading club" },
    { votes: 133, postTitle: "QSC", username: "benisphere",body:" The queens space conference"}
  ]
};
class Posts {
  constructor(upvotes,downvotes,postTitle,author,body,comments) { 
    this.upvotes=upvotes
    this.downvotes=downvotes
    this.postTitle=postTitle
    this.author=author
    this.body=body
    this.comments=[]
    this.comments = comments // This should be an array
  }
}

var postList= [new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team",["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"])]
postList.push(new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team",["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"]))
postList.push(new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team",["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"]))  

var cat="Clubs";

function Home(){



    const [name,setName]= useState('david');
;


    const category="Clubs";

    function createPost(e){
        setName('David',e);

      
        postList.push(new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team"));
    }




    return ( 
        <div className="home">
            
            <h1>  Queens Core: {cat} </h1>
            <Link to="/CreatePost">
                <button onClick={createPost}>  Create Post </button>
            </Link>
            <div className="posts">


            {postList.length > 0 ? (
        postList.map((post, index) =>
         <div style={{backgroundColor: '#ee3000'}} className='posts' key={index}>
            {postList.length}|
            {post.downvotes}Upvotes||
            {post.downvotes}Down|| 
            {post.postTitle} Posted by: {post.author} 
            <p>{post.body}</p>
            {postList[1].comments.length > 0 ? (postList[1].comments.map((comment, indexC) =>
            <div style={{backgroundColor: '#ffffff'}} className='comments' key={indexC}>

              <p>{comment}</p>
              
            </div>
            
            )) : (<div>No Comments</div>)}
              
              
              <button>add comment</button>  
          </div>

           )
      ) : (
        <div>No Posts </div>
      )} 
        {postList[1].comments.length > 0 ? (postList[1].comments.map((comment, indexC) =>
          <div style={{backgroundColor: '#ee4000'}} className='comments' key={indexC}>

            <p>{comment}</p>
    
          </div>
           )) : (<div>No Comments</div>)}
      
        </div>
      </div>
        
     );

}

export default Home;