import {useState } from 'react';


const SignIn = () => {
//  going to be using state hooks to handle input 
    return ( 
        <div className="signin">
            <div className="Header"><h1>Sign in</h1></div>
            <h3>Create Account</h3>
            
            <div className="form">
                
                    <form>
                        <h3>Enter email:</h3>
                         <input type="text" placeholder='netID@queensu.ca' />
                    </form>
                
                    <form>
                        <h3>Enter password:</h3>
                         <input type="text" placeholder='Password'/>
                    </form>                    
            </div>
            
        </div>
     );
}

export default SignIn;