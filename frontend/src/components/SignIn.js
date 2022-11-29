const SignIn = () => {
    const ws =  new WebSocket('ws://127.0.0.1:2236');

    function inputToString(document) {
        return "login:"+document.getElementById("email").value+":"+document.getElementById("password").value;
    }

    return ( 
        <div className="signin">
            <div className="Header"><h1>Sign in</h1></div>
            <h3>Create Account</h3>
            <div className="form">
                <h3>Enter email:</h3>
                <input id="email" type="text" placeholder='netID@queensu.ca' />
                <h3>Enter password:</h3>
                <input id="password" type="text" placeholder='Password'/>
                <button type="submit" onClick = {() => ws.send(inputToString(document))}>Sign In</button>
            </div>
            
        </div>
     );
}

export default SignIn;