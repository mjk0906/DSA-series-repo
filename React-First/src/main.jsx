import { StrictMode } from 'react'
import { createElement } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'

//another way to write or create an element in jsx
// import { createElement } from 'react'

// const heading = createElement("h1",null,"hello react World")
// console.log(heading)
// use the { heading } in the render to have the heading rendered

// function MainContent(){
//   return <h1> React is Great guys</h1>
// }
const root = createRoot(document.getElementById('root'))
function Tempo(){ //first letter capital in the name of fn 
    return(
      <main>
        <img src="react-logo.png" width="40px" alt="React logo" />
        <h1>Fun facts about React!</h1>
        <ul>
            <li>Was first release in 2013</li>
            <li>Was originally created by Jordan Walke</li>
            <li>Has well over 200K stars on GitHub</li>
            <li>Is maintained by Meta</li>
            <li>Powers thousands of enterprise apps, including mobile apps</li>
        </ul>
      </main>
    )
}
root.render(
  // <div>
  //   <h1 className = "header">This is Decalarative coding</h1>
  //   <img src = "reactlogo.svg" />
  // </div>
  //we can also use main,article containers also
  <Tempo/>
)
// way of imerative coding ( not needed in react )
// const h1 = document.createElement("h1")
// h1.textContent = "This is imperative Coding"
// h1.className = "newclass"
// document.getElementById("root").appendChild(h1)
// createRoot(document.getElementById('root')).render(
//   <StrictMode>
//     <App />
//     <h1>"hellowww Worlddd!!!</h1>
//     <MainContent />
//   </StrictMode>
// )

// we can have like