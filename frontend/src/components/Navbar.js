const Navbar = () =>{
    return(
        <nav className="navbar">
            <className className="headers">            
                <h1 style={{float:'left'}}>Queens</h1> 
                <h1 style={{color: '#ee3000'}}> CORE</h1>
            </className>




            <div className="links">
                <a href="/">Home</a>
                <a href="/About">About</a>
                <a href="/signIn">Sign In </a>
                <a href="/CreatePost">Create Post</a>
                <a href="/Profile">Profile</a>

            </div>
        </nav>
    );
}

export default Navbar;