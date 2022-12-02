
import { getAllByPlaceholderText } from '@testing-library/react';
import {useState } from 'react';
import CreatePost from './CreatePost';

var usersData = {
  total: 3,
  data: [
    { votes: 321, postTitle: "QMIND", username: "floppydiskette", body: "Queens Ai design club"},
    { votes: 163, postTitle: "QUANTT", username: "siliconeidolon", body: "A quantatative trading club" },
    { votes: 133, postTitle: "QSC", username: "benisphere",body:" The queens space conference"}
  ]
};
class Posts {
  constructor(upvotes,downvotes,postTitle,author,body) { 
    this.upvotes=upvotes
    this.downvotes=downvotes
    this.postTitle=postTitle
    this.author=author
    this.body=body
  }
}

var postList= [new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team")]

  

var cat="Clubs";

function Home(){



    const [name,setName]= useState('david');
;


    const category="Clubs";
    // createPost = post{
        

      
    //     postList.push(new Posts(1,2,"QMIND","David Hoernke","An Ai focused design team"));
    // }




    return ( 
        <div className="home">
            
            <h1>  Queens Core: {cat} </h1>
            
            <button onClick={this.createPost}>  Create Post </button>
            <div className="posts">


            {postList.length > 0 ? (
        postList.map((post, index) => <div style={{backgroundColor: '#ee3000'}} className='posts' key={index}> {postList.length}|{post.downvotes}Upvotes|| {post.downvotes}Down|| {post.postTitle} Posted by: {post.author} <p>{post.body}</p></div>)
      ) : (
        <div>No Posts </div>
      )} 


            {/* {usersData.data.length > 0 ? (
        usersData.data.map((post, index) => <div style={{backgroundColor: '#ee3000'}} className='posts' key={index}> {post.votes} {post.postTitle} Posted by: {post.username} <p>{post.body}</p></div>)
      ) : (
        <div>No Posts </div>
      )} */}
      
      </div>
        </div>
        
     );

}

export default Home;