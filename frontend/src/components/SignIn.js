import React, { useState } from 'react';
import { useCookies } from 'react-cookie';



const socket =  new WebSocket('ws://127.0.0.1:2236');


const SignIn = () => {
        const [name, setName] = useState('');
        const [cookies, setCookie] = useCookies(['user']);



        const handle = () => {
            setCookie('Name',name,{path:'/'});

        }

    // Listen for messages
    socket.addEventListener('message', (event) => {
        alert("Signed in as " +event.data);
        setName(event.data);
        handle();
    });



    function logInputToString(document) {
            return "signin:"+document.getElementById("email").value+":"+document.getElementById("password").value;
        }

        function registerInputToString(document) {
            return "register:"+document.getElementById("registeremail").value+":"
                +document.getElementById("registerusername").value+":"
                +document.getElementById("registerpassword").value+":"
            +document.getElementById("registerpassword").value;
        }

//  going to be using state hooks to handle input 
    const SchoolName = "Queen's"
    return ( 
        <div className="signin">
            <div className="form">
                <h1>Sign in</h1>   
                    <form>
                        <h3>Enter {SchoolName} email:</h3>
                         <input type="text" placeholder='netID@queensu.ca' id="email" />
                    </form>
                
                    <form>
                        <h3>Enter password:</h3>
                         <input type="text" placeholder='Password' id="password"/>
                    </form>
                    <button type="submit" onClick = {() => socket.send(logInputToString(document))}>Sign In</button>
            </div>
            
            <div className="form2">
                <h1>Create Account</h1>
                <form>
                    <h3>Enter {SchoolName} email:</h3>
                     <input type="text"  placeholder='netID@queensu.ca' id="registeremail"/>
                </form>
                <h3>Username:</h3>
                <form action="">
                    <input type="text"  placeholder='user name' id="registerusername"/>
                </form>
                <form>
                    <h3>Enter password:</h3>
                     <input type="text" placeholder='Password' id="registerpassword"/>
                </form>    
                <form>
                    <h3>Confirm password:{cookies.Name}</h3>
                     <input type="text" placeholder='registerPassword'/>
                </form>           
                <button type="submit" onClick = {() => socket.send(registerInputToString(document))}>Create Account</button>
        </div>
        </div>
     );
}


export default SignIn;