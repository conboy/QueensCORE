import {useState } from 'react';


const SignIn = () => {
//  going to be using state hooks to handle input 
    const SchoolName = "Queen's"
    return ( 
        <div className="signin">
            
            <div className="form">
                <h1>Sign in</h1>   
                    <form>
                        <h3>Enter {SchoolName} email:</h3>
                         <input type="text" placeholder='netID@queensu.ca' />
                    </form>
                
                    <form>
                        <h3>Enter password:</h3>
                         <input type="text" placeholder='Password'/>
                    </form>                    
            </div>
            
            <div className="form2">
                <h1>Create Account</h1>
                <form>
                    <h3>Enter {SchoolName} email:</h3>
                     <input type="text" placeholder='netID@queensu.ca' />
                </form>
            
                <form>
                    <h3>Enter password:</h3>
                     <input type="text" placeholder='Password'/>
                </form>    
                <form>
                    <h3>Confirm password:</h3>
                     <input type="text" placeholder='Password'/>
                </form>                 
        </div>
            
        </div>
     );
}

export default SignIn;