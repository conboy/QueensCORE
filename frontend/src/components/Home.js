import { getAllByPlaceholderText } from '@testing-library/react';
import {useState } from 'react';
import { BrowserRouter as Router,Link } from 'react-router-dom';

var tempBio = "QMIND is Canada’s largest student-run organization. We empower undergraduate student’s at Queen’s University to tackle real-world problems through the use of artificial intelligence, machine learning, and various other disruptive technologies. Our organization spans over 200 members, 30+ design teams, a consulting stream, a published AI research wing, an incubator program, and a national-scale conference with 400+ delegates held annually in Toronto, ON.Our mandate is to lower the entry barriers preventing undergraduate students to work on complex problems using disruptive technologies. Since inception, our design teams have completed 150+ projects and our members have gone to work at North America’s largest including McKinsey, Microsoft, Google, Amazon, etc.";



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

var postList= [new Posts(1,2,"QMIND","David Hoernke",tempBio,["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"])]
postList.push(new Posts(1,2,"QMIND","David Hoernke",tempBio,["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"]))
postList.push(new Posts(1,2,"QMIND","David Hoernke",tempBio,["David : This sucks!!", "Ethan : Wow this looks too cool", "Liam : I absolutely garb at coding LOL"]))  

var cat="Clubs";

function Home(){

    const ws =  new WebSocket('ws://127.0.0.1:2236');

    function UpVoteInputToString(document,Title){
        return "UpVote:"+Title;
    }
    function DownVoteInputToString(document,Title){
        return "DownVote:"+Title;
    }
    function CommentInputToString(document,Title,Author){
      return "comment:"+Title+":"+Author+":"+document.getElementByID("addComment");
    }

    const [name,setName]= useState('david');



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

          <button onClick={() => ws.send(UpVoteInputToString(document,post.postTitle))} style={{float: "left",backgroundColor:'green'}}>{post.upvotes} Up Votes</button> 

          <button onClick={() => ws.send(DownVoteInputToString(document,post.postTitle))} style={{float: "left",backgroundColor:'red'}}>{post.downvotes} Down Votes</button> 
            
            <h2 style={{float: "left"}}>{post.postTitle}</h2><h3 style={{textAlign:"right"}}>Posted by: {post.author}</h3>
            <p> </p>
            <p style={{tempBio}}>{post.body}</p>
            <div style={{textAlign:'left'}} className="comments">
              <h3 style={{textDecoration:'bold', fontSize:23}}>Comments:</h3>
              {postList[index].comments.length > 0 ? (postList[index].comments.map((comment, indexC) =>
              <div key={indexC}>
                <div><p style={{marginLeft:5}}>{comment}</p></div>
                
                
              </div>
            
            )) : (<div>No Comments</div>)}
              
              <form style={{margin:5, float:'left'}}>
                     <input type="text" placeholder='Comment' id="addComment"/>
              </form> 
              <button style={{marginBottom:10}} type="submit" onClick={() => ws.send(CommentInputToString(document,post.postTitle,post.author))}>add comment</button>  
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