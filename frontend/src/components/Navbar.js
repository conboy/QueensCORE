const Navbar = () =>{
    return(
        <nav className="navbar">
            {/* <img src="logo.png" alt="nothing" width="500" height="333"/> */}
            <h1>Queens</h1> 
            <h1 style={{color: '#ee3000'}}> CORE</h1> 
            <div className="links">
                <a href="/">Home</a>
                <a href="/About">About</a>
                <a href="/signIn">Sign In </a>


            </div>
        </nav>
    );
}

export default Navbar;