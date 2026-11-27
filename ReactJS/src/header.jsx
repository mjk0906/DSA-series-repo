export default function Header(){
  return(
    <nav>
      <ul className = "navList">
        <li>Prev</li>
        <li>Curr Details</li>
        <li>Next Page</li>
      </ul>
    </nav>
  )
}
//this is the header as a seperate code file, we need to export it and import it where we have to render the file