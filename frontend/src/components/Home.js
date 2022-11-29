import {useState } from 'react';


const Home = () => {
    const [name,setName]= useState('david');

    const handleClick = (e) =>{
        console.log('you clicked that button good !',e);
        setName('Davad');
    }



    return ( 
        <div className="home">
            
            <h2>HomePage</h2>
            <p>{name}</p>
            <button onClick={handleClick}>  Click Me</button>
            <button onClick={()=>console.log('Set_Name')}> clicked</button>
        </div>
     );
}

export default Home;