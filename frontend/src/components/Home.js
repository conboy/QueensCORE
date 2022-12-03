import { getAllByPlaceholderText } from '@testing-library/react';
import {useState } from 'react';
import { BrowserRouter as Router,Link } from 'react-router-dom';


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
            <div className="postss">


            {postList.length > 0 ? (
        postList.map((post, index) =>
         <div  className="posts" key={index}>

          <button style={{float: "left",backgroundColor:'green'}}>{post.upvotes} Up Votes</button> 

          <button style={{float: "left",backgroundColor:'red'}}>{post.downvotes} Down Votes</button> 
            
            <h2 style={{float: "left"}}>{post.postTitle}</h2><h3 style={{textAlign:"right"}}>Posted by: {post.author}</h3>
            <p style={{textAlign:"left"}}>{post.body}</p>
            <div className="comments">
              <h3 style={{}}>Comments:</h3>
              {postList[1].comments.length > 0 ? (postList[1].comments.map((comment, indexC) =>
              <div key={indexC}>
                <div><p >{comment}</p></div>
                
                
              </div>
            
            )) : (<div>No Comments</div>)}
              
              
              <button>add comment</button>  
            </div>
          </div>

           )
      ) : (
        <div>No Posts </div>
      )} 

      
        </div>
      </div>
     );
}

export default Home;