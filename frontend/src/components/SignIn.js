
const SignIn = () => {

        const ws =  new WebSocket('ws://127.0.0.1:2236');
    
        function logInputToString(document) {
            return "login:"+document.getElementById("email").value+":"+document.getElementById("password").value;
        }

        function registerInputToString(document) {
            return "register:"+document.getElementById("registeremail").value+":"+document.getElementById("registerpassword").value;
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
                    <button type="submit" onClick = {() => ws.send(logInputToString(document))}>Sign In</button>
            </div>
            
            <div className="form2">
                <h1>Create Account</h1>
                <form>
                    <h3>Enter {SchoolName} email:</h3>
                     <input type="text" placeholder='netID@queensu.ca' id="registeremail"/>
                     
                </form>
            
                <form>
                    <h3>Enter password:</h3>
                     <input type="text" placeholder='Password' id="registerpassword"/>
                </form>    
                <form>
                    <h3>Confirm password:</h3>
                     <input type="text" placeholder='Password'/>
                </form>           
                <button type="submit" onClick = {() => ws.send(registerInputToString(document))}>Create Account</button>
        </div>
            
        </div>
     );
}

export default SignIn;